#!/usr/bin/perl 
#===============================================================================
#
#         FILE:  httpd.pl
#
#        USAGE:  ./httpd.pl  
#
#  DESCRIPTION:  a goopy sloopy server for journal things
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  1.0
#      CREATED:  14-01-2011 23:32:54
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;



use AnyEvent::HTTPD;

my $httpd = AnyEvent::HTTPD->new (port => 9090);

$httpd->reg_cb (
   '/' => sub {
      my ($httpd, $req) = @_;

      $req->respond ({ content => ['text/html',
         "<html><body><h1>Hello World!</h1>"
         . "<a href=\"http://127.0.0.1:9090/test\">another test page</a>"
         . "</body></html>"
      ]});
   },
   '/test' => sub {
      my ($httpd, $req) = @_;

      $req->respond ({ content => ['text/html',
         "<html><body><h1>Test page</h1>"
         . "<a href=\"http://127.0.0.1:9090/\">Back to the main page</a>"
         . "</body></html>"
      ]});
   },
);

$httpd->run; # making a AnyEvent condition variable would also work

