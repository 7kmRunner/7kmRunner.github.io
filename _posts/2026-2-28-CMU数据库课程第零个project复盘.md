---
layout: post
title: "CMU数据库课程Project0复盘"
date: 2026-2-28
tags: [编程]
comments: true
author: Minrain
---
##  一.关于git
git是关系型数据库，git文件中存储压缩后的代码文件对象，极度省空间；git --bare clone可以只克隆git文件，不克隆里面的代码文件。

## 二、关于任务 
首先是整个C++的基础知识：命名空间、模版声明、显式构造（拒绝自动转换类型，类型不匹配就报错）、7个自动函数（参数构造、默认构造、拷贝构造、拷贝赋值、移动构造、移动赋值、析构函数，可切成delete）。

最重要的并发无锁编程的atomic：给一个变量声明atomic，然后使用compare_exchange_strong/weak(expected,desired)来避免线程冲突，原理如下：A，B双方先读变量，如果A做完了比较，它就过去更改变量；B比较发现不对，CAS返回flase，重新操作。这里要注意：A先做完比较，但还没来得及改；B也做完，由总线程决定谁先去改，另一个会被阻挡，返回失败；A改后，B比较看到的一定是改后的状态而不是中间状态，这由atomic保证。