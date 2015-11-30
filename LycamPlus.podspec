Pod::Spec.new do |s|
  s.name = 'LycamPlus'
  s.version = '0.1.0'
  s.summary = 'A short description of LycamPlus.'
  s.license = 'MIT'
  s.authors = {"no777"=>"wt@lycam.tv"}
  s.homepage = 'https://github.com/lycam/LycamPlusSDK-iOS'
  s.description = ''
  s.frameworks = ["UIKit", "MobileCoreServices", "CoreMedia", "AVFoundation", "CoreLocation", "Foundation", "AudioToolbox", "CFNetwork", "SystemConfiguration", "ImageIO"]
  s.libraries = ["sqlite3", "c++"]
  s.requires_arc = true
  s.source = {}

  s.platform = :ios, '7.0'
  s.ios.platform             = :ios, '7.0'
  s.ios.preserve_paths       = 'ios/LycamPlus.framework'
  s.ios.public_header_files  = 'ios/LycamPlus.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'ios/LycamPlus.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/LycamPlus.framework'
end
