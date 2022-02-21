from __future__ import absolute_import,division,print_function
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
# 导入数据集并划分训练集和测试集
(x_train,y_train),(x_test,y_test) = keras.datasets.mnist.load_data()
x_train = x_train.reshape(6000,784).astype('float32') / 255
x_test = x_test.reshape(10000,784).astype('float32') /255
# 以10000划分数据集
x_val = x_train[-10000:]
y_val = y_train[-10000:]
x_train = x_train[:-10000]
y_train = y_train[:-10000]
# 构建模型函数
def get_compiled_model():
    # 建立输入层
    inputs = keras.Input(shape=(784,),name='mnist_input')
    h1 = layers.Dense(64,activation='relu')(inputs)
    h2 = layers.Dense(64,activation='relu')(h1)
    # 建立输出层
    outputs =layers.Dense(10,activation='softmax')(h2)
    # 使用keras构建模型
    model = keras.Model(inputs,outputs)
    model.compile(optimizer=keras.optimizers.RMSprop(),loss=keras.losses.SparseCategoricalCrossentropy(),metrics=[keras.metrics.SparseCategoricalAccuracy()])
    return model

# 定义模型
model = get_compiled_model()
# 建立训练集
train_dataset = tf.data.Dataset.from_tensor_slices((x_train,y_train))
train_dataset = train_dataset.shuffle(buffer_size=1024).batch(64)
# 建立测试集
val_dataset = tf.data.Dataset.from_tensor_slices((x_val,y_val))
val_dataset = val_dataset.batch(64)
model.fit(train_dataset,epochs=3,step_per_epoch=100,validation_data=val_dataset,validation_steps=3)


