'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    watch: {
      options: {
        livereload: true
      },
      sass: {
        files: ['sass/{,**/}*.{scss,sass}'],
        tasks: ['compass']
      },
      images: {
        files: ['images/**']
      },
      css: {
        files: ['stylesheets/{,**/}*.css']
      },
      js: {
        files: ['js/{,**/}*.js', '!js/{,**/}*.js'],
        tasks: ['jshint', 'uglify:dev']
      }
    },

    compass: {
      all: {
        options: {
          environment: 'production',
          force: true,
          config: 'config.rb',
          bundleExec: true
        }
      }
    },

    jshint: {
      options: {
        jshintrc: '.jshintrc'
      },
      all: ['js/{,**/}*.js', '!js/{,**/}*.min.js']
    },

    uglify: {
      options: {
        mangle: false,
        compress: false
      },
      all: {
        files: {
          'js/jquery.matchmedia.min.js': ['js/jquery.matchmedia.js'],
          'js/jquery.resizeend.min.js': ['js/jquery.resizeend.js'],
          'js/jquery.scrollable.min.js': ['js/jquery.matchmedia.js'],
          'js/omega.admin.min.js': ['js/omega.admin.js'],
          'js/omega.indicator.min.js': ['js/omega.indicator.js'],
          'js/omega.mediaqueries.min.js': ['js/omega.mediaqueries.js'],
          'js/omega.messages.min.js': ['js/omega.messages.js']
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-uglify');

  grunt.registerTask('build', [
    'uglify',
    'compass',
    'jshint'
  ]);

};
