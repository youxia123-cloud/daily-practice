# 自编码器
import tensorflow as tf
import tensorflow.keras as keras
import tensorflow.keras.layers as layers
from Ipython.display import SVG
import matplotlib.pyplot as plt
# 导入数据集
(x_train,y_train),(x_test,y_test) = keras.dataset.mnist.load_data()
x_train = x_train.reshape((-1,28*28))/255.0
x_test = x_test.reshape((-1,28*28))/255.0
code_dim = 32
# 建立输出层
inputs = layers.Input(shape=(x_train.shape[1],),name='inputs')
code = layers.Dense(code_dim,activation='relu',name='code')(inputs)
outputs = layers.Dense(x_train.shape[1],activation='softmax',name='outputs')(code)
# 构建自编码器
auto_encoder = keras.Model(inputs,outputs)
auto_encoder.summary()
# 使用自编码器对设置的层进行编码
keras.utils.plot_model(auto_encoder,show_shapes=True)
encoder = keras.Model(inputs,code)
keras.utils.plot_model(encoder,show_shapes=True)
# 构建解码器
decoder_input = keras.Input((code_dim,))
decoder_output = auto_encoder.layers[-1](decoder_input)
decoder = keras.Model(decoder_input,decoder_output)
keras.utils.plot_model(decoder,show_shapes=True)
# 使用解码器对编码后的层解码
auto_ecoder.compile(optimizer='adam',loss='binary_crossentropy')
# 对设置的模型进行训练
history = auto_encoder.fit(x_train.y_train,batch_size=64,epochs=10,validation_split=0.1)
# 对自编码器和解码器进行预测
encoded = encoder.predict(x_test)
decoded = decoded.predict(encoded)
plt.figure(figise=(10,4))
# 循环构建数据并显示图像
n = 5
for i in range(n):
    ax = plt.subplot(2,n,i+1)
    plt.imshow(x_test[i].reshape(28,28))
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)
    ax = plt.subplot(2,n,n+i+1)
    plt.imshow(decoded[i].reshape(28,28))
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)
plt.show()



