# 使用构建的数据集构建卷积层
# 加入池化层
# 加入全连接层
import ssl
from tensorflow import keras
from tensorflow.keras import layers
import matplotlib.pyplot as plt
ssl._create_deault_https_context = ssl._create_unverified_context
# 导入MNIST数据集
(x_train,y_train),(x_test,y_test) = keras.datasets.mnist.load_data()
x_train =x_train.reshape((-1,28,28,1))
x_test = x_test.reshape((-1,28,28,1))
# 使用序贯模型
model = keras.Sequential()
# 使用conv2d构建卷积层
model.add(layers.Conv2D(input_shape=(x_train.shape[0],x_train.shape[1],x_train.shape[2]),filters=32,kernel_size=(3,3),
            strides=(1,1),padding='valid',activation='relu'))
# 添加一个pool_size=(2,2)的最大池化层
model.add(layers.MaxPool2D(pool_size=(2,2)))
# 将输入展平，不影响批量大小。这里使用默认值channels_last
model.add(layers.Flatten())
# 分类层
model.add(layers.Dense(32,activation='relu'))
# 连接层，相当于添加一个层
model.add(layers.Dense(10,activation='softmax'))
# 编译模型
model.compile(optimizer=keras.optimizers.Adam(),loss=keras.losses.SparseCategoricalCrossentropy(),metrics=['accuracy'])
# 输出各层的情况
model.summary()
# 训练5次
history = model.fit(x_train,y_train,batch_size=64,epochs=5,validation_split=0.1)
# 显示训练结果
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.lengend(['training','valivation'],loc='upper left')
plt.show()




