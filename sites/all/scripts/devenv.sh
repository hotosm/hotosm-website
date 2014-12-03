#!/bin/sh
# @description: Simple script to setup the development environment

# Set the follwing line at the end of your settings.php 
# $conf['stage_file_proxy_origin'] = 'http://hotosm.org'; 

drush dis -y boost
drush en -y devel stage_file_proxy


