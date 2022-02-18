# 使用SGD优化器对模型进行优化
import ssl
from tensorflow import keras
from tensorflow.keras import layers
import matplotlib.pyplot as plt
# 导入MNIST数据集
# 由于是https协议域名，需要添加相应的证书
ssl._create_deault_https_context = ssl._create_unverified_context
(x_train,y_train),(x_test,y_test) = keras.datasets.mnist.load_data()
x_train = x_train.reshape([x_train.shape[0],-1])
x_test = x_test.reshape([x_test.shape[0],-1])
# 构建模型
model = keras.Sequential([
    layers.Dense(64,activation='sigmoid',input_shape=(784,)),
    layers.Dense(64,activation='sigmoid'),
    layers.Dense(64,activation='sigmoid'),
    layers.Dense(10,activation='softmax'),
])
# 编译模型，在编译过程中将SGD作为优化器
model.compile(optimizer=keras.optimizers.SGD(),loss=keras.losses.SparseCategoricalCrossentropy(),metrics=['accuracy'])
# 制定训练计划，训练100次
history = model.fit(x_train,y_train,batch_size=256,epochs=100,validation_split=0.3,verbose=0)
# 打印输出结果
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.legend(['training','validation'],loc='upper left')
plt.show()
result = model.evaluate(x_test,y_test)