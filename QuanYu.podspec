Pod::Spec.new do |s|
  #pod私有库名称
  s.name             = 'QuanYu'
  #pod私有库版本号
  s.version          = '0.1.2'
  #pod私有库概要
  s.summary          = 'striver custom QuanYu'
  #主要，最好能访问
  s.homepage         = 'https://github.com/XYRZX/QuanYuSDK/tree/master'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  #开源协议
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  #开源作者
  s.author           = 'XYRZX'
  #源码地址，clone时候就需要使用这个地址跟版本拉取
  s.source           = { :git => 'https://github.com/XYRZX/QuanYuSDK.git', :tag =>'0.1.2' }
  #支持的系统版本
  s.ios.deployment_target = '8.0'
  #源码相对路径
  s.source_files = 'QuanYu.framework/*/**'

  #依赖第三方库
  s.dependency "SocketRocket"
  s.dependency "Reachability"
end
