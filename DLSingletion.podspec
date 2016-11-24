Pod::Spec.new do |s|
s.name = 'DLSingletion'
s.version = '1.0.0'
s.license = 'MIT'
s.summary = '快速创建单例'
s.homepage = 'https://github.com/JiangYelinGit/DLSingletion'
s.authors = { 'JiangYelin' => '897134699@qq.com' }
s.source = { :git => "https://github.com/JiangYelinGit/DLSingletion.git", :tag => s.version.to_s }
s.requires_arc = true
s.ios.deployment_target = '8.0'
s.source_files = 'DLSingletion/*.{h,m}'
end