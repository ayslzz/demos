## 概述

这是一个使用了openssl库的简单HTTPS客户端示例项目，可以指定域名（或地址）的某端口发送一个HTTPS请求报文。

代码用纯C语言编写，在使用前需要编译。

## 编译

在代码目录中执行

``` shell
make
```

## 运行

编译成功后，可执行文件名称为`ssl_client`

注意：若当前系统没有openssl动态库，需要先在`代码顶级目录`中执行如下命令，将项目中的lib目录添加到程序动态库的查找路径中

``` shell
export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
```

## 举例

下面命令向`https://www.openssl.org`发送HTTPS请求，内容包含在`example/http_req`文件中

``` shell
./ssl_client www.openssl.org 443 example/http_req
```

http_req文件的内容为
``` http
GET / HTTP/1.1
HOST: www.openssl.org

```