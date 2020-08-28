# BearGame
BearGame 目标是成为一个 五脏俱全 具有教学意义的游戏服务器框架.

## Todo
### 日志
* 日志支持滚动
* 支持多线程日志输出
### 配置
* 根据配置生成 配置读取代码
* 支持多线程配置读取
* 支持 热更新
### 网络
* 接入 BearNet(采用 epoll I/O多路复用 实现的一个TCP网络库)
* 实现 UDP + KCP(部分游戏可能用到UDP)
* 实现基础的封包解包
### Lua
* 封装 lua, 将 service 与 lua state 绑定
* 使用 lua 来完成基础业务逻辑
