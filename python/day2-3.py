# Pytorch生成对抗网络编程，生成1010格式规律
import torch
import torch.nn as nn
import pandas
import matplotlib.pyplot as plt
import random


def generate_real():
    real_data = torch.FloatTensor([
        random.uniform(0.8, 1.0),
        random.uniform(0.0, 0.2),
        random.uniform(0.8, 1.0),
        random.uniform(0.0, 0.2)
    ])
    return real_data


# 鉴别器的构造函数
class Discriminator(nn.Module):

    def __init__(self):
        # 初始化pytorch父类
        super().__init__()
        # 定义神经网络层
        self.model = nn.Sequential(
            nn.Linear(4, 3),
            nn.Sigmoid(),
            nn.Linear(3, 1),
            nn.Sigmoid()
        )
        # 创建损失函数
        self.loss_function = nn.MSELoss()
        # 创建优化器，使用随机梯度下降
        self.optimiser = torch.optim.SGD(self.parameters(), lr=0.01)
        # 计数器和进程记录
        self.counter = 0
        self.progress = []
        pass

    def forward(self, inputs):
        # 直接运行模型
        return self.model(inputs)

    def train(self, inputs, targets):
        # 计算网络的输出
        outputs = self.forward(inputs)
        # 计算损失值
        loss = self.loss_function(outputs, targets)
        # 每训练10次增加计数器
        self.counter += 1
        if (self.counter % 10 == 0):
            self.progress.append(loss.item())
            pass
        if (self.counter % 10000 == 0):
            print("counter=", self.counter)
            pass

        # 归零梯度，反向传播，并更新权重
        self.optimiser.zero_grad()
        loss.backward()
        self.optimiser.step()
        pass

    def plot_progress(self):
        df = pandas.DataFrame(self.progress, columns=['loss'])
        df.plot(ylim=(0, 1.0), figsize=(16, 8), alpha=0.1, marker='.', grid=True, yticks=(0, 0.25, 0.5))
        pass


# 构建生成器
class Generator(nn.Module):

    def __init__(self):
        # 初始化Pytorch父类
        super().__init__()
        # 定义伸进网络层
        self.model = nn.Sequential(
            nn.Linear(1, 3),
            nn.Sigmoid(),
            nn.Linear(3, 4),
            nn.Sigmoid(),
        )
        # 创建优化器
        self.optimiser = torch.optim.SGD(self.parameters(), lr=0.01)
        # 计数器和进程记录
        self.counter = 0
        self.progress = []
        pass

    def forward(self, inputs):
        # 直接运行模型
        return self.model(inputs)

    def train(self, D, inputs, targets):
        # 计算网络输出
        g_output = self.forward(inputs)

        # 输入鉴别器
        d_output = D.forward(g_output)

        # 计算损失值
        loss = D.loss_function(d_output, targets)
        # 每训练10次增加计数器
        self.counter += 1
        if (self.counter % 10 == 0):
            self.progress.append(loss.item())
            pass
        # 梯度归零，反向传播，并更新权重
        self.optimiser.zero_grad()
        loss.backward()
        self.optimiser.step()
        pass

    def plot_progress(self):
        df = pandas.DataFrame(self.progress, columns=['loss'])
        df.plot(ylim=(0, 1.0), figsize=(16, 8), alpha=0.1, marker='.', grid=True, yticks=(0, 0.25, 0.5))
        pass


G = Generator()
G.forward(torch.FloatTensor([0.5]))

# 创建鉴别器和生成器
D = Discriminator()
G = Generator()
# 训练鉴别器和生成器
for i in range(10000):
    # 用真实样本训练鉴别器
    D.train(generate_real(), torch.FloatTensor([1.0]))
    # 用生成样本训练鉴别器
    # 使用detach（）以避免计算生成器G中的梯度
    D.train(G.forward(torch.FloatTensor([0.5])).detach(), torch.FloatTensor([0.0]))
    # 训练生成器
    G.train(D, torch.FloatTensor([0.5]), torch.FloatTensor([1.0]))
    pass

D.plot_progress()
G.plot_progress()