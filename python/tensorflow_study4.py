# 反向传播算法实例
# 实现一个四层的全连接网络实现二分类任务。网络的输入结点为2，隐藏层的节点数设计为25,50,25，输出层两个节点，分别表示属于类别1的概率和属于类别2的概率
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.datasets import make_moons
from sklearn.model_selection import train_test_split
N_SAMPLES = 2000 # 采样点数
TEST_SIZE = 0.3 # 测试数量比例
# 利用工具函数直接生成数据集
X,y = make_moons(n_samples=N_SAMPLES,noise=0.2,random_state=100)
# 将2000个点按7:3分割成训练集和测试集
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=TEST_SIZE,random_state=42)
print(X.shape,y.shape)
# 可视化数据的分布
def make_plot(X,y,plot_name,file_name=None,XX=None,YY=None,preds=None,dark=False):
    if(dark):
        plt.style.use('dark_background')
    else:
        sns.set_style("whitegrid")
    plt.figure(figsize=(16,12))
    axes = plt.gca()
    axes.set(xlabel="$x_1$",ylabel="$x_2$")
    plt.title(plot_name,fontsize=30)
    plt.subplots_adjust(left=0.20)
    plt.subplots_adjust(right=0.80)
    if(XX is not None and YY is not None and preds is not None):
        plt.contourf(XX,yy,preds.reshape(XX.shape),25,alpha=1,cmap=plt.cm.Spectral)
        plt.contourf(XX,yy,preds.reshape(XX.shape),levels[.5],cmap="Greys",vmin=0,vmax=.6)
    # 绘制散点图，根据标签区分颜色
    plt.scatter(X[:,0],X[:,1],c=y.ravel(),s=40,cmap=plt.cm.Spectral,edgecolors='none')
    plt.savefig("dataset.svg")
    plt.close()
# 调用make_plot函数绘制数据的分布，其中x为2D坐标，y为标签
make_plot(X,y,"Classification Dataset Visualization")
plt.show()
# 定义网络层
class Layer:
    # 全连接网络层
    def __init__(self,n_input,n_neursons,activation=None,weights=None,bias=None):
        """
        :param int n_input:输入节点数
        :param int n_neursons:输出节点数
        :param str activation:激活函数类型
        :param weights:权重张量，默认类内部生成
        :param bias:偏置，默认类内部生成
        """
        # 通过正态分布初始化网络权值，初始化非常重要，不合适的初始化将导致网络不收敛
        self.weights = weights if weights is not None else np.random.randn(n_input,n_neursons)*np.sqrt(1/n_neursons)
        self.bias = bias if bias is not None else np.random.rand(n_neursons)*0.1
        self.activation = activation # 激活函数的类型，如“sigmoid”
        self.last_activation = None # 激活函数的输出值o
        self.error = None # 用于计算当前层的delat变量的中间变量
        self.delta = None # 记录当前层的delta变量，用于计算梯度
    # 实现网络层的前向传播
    def activate(self,x):
        # 前向传播
        r = np.dot(x,self.weights) + self.bias # X@W+b
        # 通过激活函数，得到全连接层的输出o
        self.last_activation = self._apply_activation(r)
        return self.last_activation

    # 计算激活函数的输出
    def _apply_activation(self,r):
        if self.activation is None:
            return r # 无激活函数，直接返回
        # relu激活函数
        elif self.activation == 'relu':
            return np.maxium(r,0)
        # tanh激活函数
        elif self.activation == 'tanh':
            return np.tanh(r)
        # sigmoid激活函数
        elif self.activation == 'sigmoid':
            return 1/(1+np.exp(-r))

        return r
    # 计算激活函数的导数
    def apply_activation_derivative(self,r):
        # 无激活函数，导数为1
        if self.activation is None:
            return np.ones_like(r)
        # ReLU函数的导数实现
        elif self.activation == 'relu':
            gard = np.array(r,copy=True)
            gard[r>0] = 1.
            gard[r<0] = 0.
            return gard
        # tanh函数的导数实现
        elif self.activation == 'tanh':
            return 1 - r**2
        # sigmoid函数的导数实现
        elif self.activation =='sigmoid':
            return r * (1 - r)

        return r


# 定义网络模型的类：
class NeuralNetwork:
    # 神经网络大类
    def __init__(self):
        self._layers = [] # 网络层对象列表

    def add_layer(self,layer):
        # 追加网络层
        self._layers.append(layer)
    # 前向传播
    def feed_forward(self,X):
        for layer in self._layers:
            # 依次通过各个网络层
            X = layer.activate(X)
        return X

    # 反向传播算法的实现
    def backpropogation(self, X, y, learning_rate):
        # 前向计算，得到输出值
        output = self.feed_forward(X)
        for i in reversed(range(len(self._layers))):  # 反向循环
            layer = self._layers[i]  # 得到当前层的对象
            # 如果是输出层
            if layer == self._layers[-1]:  # 对于输出层
                layer.error = y - output  # 计算2分类任务的均方差的导数
                # 关键步骤：计算最后一层的delta，参考输出层的梯度公式
                layer.delta = layer.error * layer.apply_activation_derivative(output)
            else:  # 如果是隐藏层
                next_layer = self._layers[i + 1]  # 得到下一层对象
                layer.error = np.dot(next_layer.weights, next_layer.delta)
                # 关键步骤：计算隐藏层的delta，参考隐藏层的梯度公式
                layer.delta = layer.error * layer.apply_activation_derivative(layer.last_activation)
        # 循环更新权值
        for i in range(len(self._layers)):
            layer = self._layers[i]
            # o_i为上一层网络的输出
            o_i = np.atleast_2d(X if i == 0 else self._layers[i - 1].last_activation)
            # 梯度下降算法，delta是公式中的负号，这里用加号
            layer.weights += layer.delta * o_i.T * learning_rate

    # 网络训练函数
    def train(self, X_train, X_test, y_train, y_test, learning_rate, max_epochs):
        # one-hot编码
        y_onehot = np.zeros((y_train.shape[0], 2))
        y_onehot[np.arange(y_train.shape[0]), y_train] = 1
        mses = []
        accuracys = []
        for i in range(max_epochs):  # 训练1000个epoch
            for j in range(len(X_train)):  # 一次训练一个样本
                self.backpropogation(X_train[j], y_onehot[j], learning_rate)
            if i % 10 == 0:
                # 打印出MSE Loss
                mse = np.mean(np.square(y_onehot - self.feed_forward(X_train)))
                mses.append(mse)
                accuracy = self.accuracy(self.predict(X_test),y_test.flatten())
                accuracys.append(accuracy)
                print('Epoch:#%s,MSE:%f' % (i, float(mse)))

                # 统计并打印准确率
                print('Accuracy:%.2f%%' % (self.accuracy(self.predict(X_test), y_test.flatten()) * 100))
        return mses,accuracys

    def predict(self,X):
        return self.feed_forward(X)

    def accuracy(self,X,y):
        return np.sum(np.equal(np.argmax(X,axis=1),y)) / y.shape[0]
# 实例化网络对象，添加四层 全连接层：
nn = NeuralNetwork() # 实例化网络类
nn.add_layer(Layer(2,25,'sigmoid')) # 隐藏层1,2=>25
nn.add_layer(Layer(25,50,'sigmoid')) # 隐藏层2,25=>50
nn.add_layer(Layer(50,25,'sigmoid')) # 隐藏层3,50=>25
nn.add_layer(Layer(25,2,'sigmoid')) # 隐藏层4,25=>2
mses,accuracys = nn.train(X_train,X_test,y_train,y_test,0.01,1000)
x = [i for i in range(0,101,10)]
# 绘制MSE曲线
plt.title("MSE Loss")
plt.plot(x,mses[:11],color='blue')
plt.xlabel('Epoch')
plt.ylabel('MSE')
plt.savefig('误差训练曲线.svg')
plt.close()

# 绘制Accuracy曲线
plt.title("Accuracy")
plt.plot(x,accuracys[:11],color='blue')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.savefig('网络预测准确.svg')
plt.close()


















