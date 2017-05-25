Pod::Spec.new do |s|
  s.name         = "HierarchyExt"
  s.version      = "0.0.1"
  s.summary      = "HierarchyExt for SafeUM"
  s.description  = "HierarchyExt is kernel extensions for SafeUM"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.source       = { :git => "https://github.com/vikvych/hierarchy_ext.git", :tag => s.version.to_s }
  s.homepage     = "https://safeum.com"
  s.authors      = { 'SafeUM' => 'info@safeum.com' }

  s.ios.deployment_target   = '8.0'
  s.source_files        = 'Include/**/*.h'
  s.public_header_files = 'Include/**/*.h'
  s.header_mappings_dir = 'Include'
  s.preserve_paths      = 'Library/libHierarchyExt.a'
  s.vendored_libraries  = 'Library/libHierarchyExt.a'

  s.libraries = 'hierarchyExt'
  s.requires_arc = false

  s.dependency 'HierarchyBase'
  
end
