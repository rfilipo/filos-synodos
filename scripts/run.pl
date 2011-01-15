#!/usr/bin/perl
#===============================================================================
#
#         FILE:  run.pl
#
#        USAGE:  ./run.pl
#
#  DESCRIPTION:  the main run for UNIX Box
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  1.0
#      CREATED:  15-01-2011 00:08:59
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;

#FIXME for Windows and MACOSX
# what my dir?
$0 =~ /^(.+[\\\/])[^\\\/]+[\\\/]*$/;
my $path = $1 || "./";
chdir("$path/..");

#the journal server
system("scripts/httpd.pl &");
sleep 3;

# the filos synodos
system("bin/Debug/vtigui");
