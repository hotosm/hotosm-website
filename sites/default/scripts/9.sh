#!/bin/sh
# @description: Replacing leadership textfield on users' profile with taxonomy reference


drush field-delete field_country -y
drush fr hot_people -y
drush cc all

