#!/bin/sh
# @description: Replacing leadership textfield on users' profile with taxonomy reference


drush field-delete field_hot_leadership -y
drush fr hot_people -y
drush cc all

