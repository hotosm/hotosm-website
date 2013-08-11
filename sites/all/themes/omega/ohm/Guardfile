notification :off

group :development do

  # Only run Compass if we have a config.rb file in place.
  if File.exists?("config.rb")
    # Compile on start.
    puts `compass compile --time --quiet`

    # https://github.com/guard/guard-compass
    guard :compass do
      watch(%r{.+\.s[ac]ss$})
    end
  end

  ## Uncomment this if you wish to clear the theme registry every time you
  ## change one of the relevant theme files.
  #guard :shell do
  #  puts 'Monitoring theme files.'
  #
  #  watch(%r{.+\.info$|^template\.php$|\.((pre)?process|theme)\.inc$|.+\.tpl\.php$}) { |m|
  #    puts 'Change detected: ' + m[0]
  #    `drush php-eval "system_rebuild_theme_data();"`
  #    puts 'Cleared info caches.'
  #  }
  #end

  # https://github.com/guard/guard-livereload.
  guard :livereload do
    watch(%r{.+\.(css|js)$})
  end

end
