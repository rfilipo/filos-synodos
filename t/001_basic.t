#
#===============================================================================
#
#         FILE:  001_basic.t
#
#  DESCRIPTION:  testes do perlVtiger
#
#        FILES:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  1.0
#      CREATED:  11-01-2011 11:25:50
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;

use Test::More tests => 8;                      # last test to print
push (@INC, '.');

require ('scripts/vtiger.pl');

our $session;
our $vtsession;
our @projectNames;
our @projectDescription;
our %projectDetails;

our $error;
my $tmp;

can_ok ('main','::getSession');
can_ok ('main','::getProjectNames');
can_ok ('main','::describeProject');
can_ok ('main','::loadProjectDetails');

getSession();
ok($session,"Verified behavior: getSession returns $session");

getProjectNames($session);
$tmp = $error?$error:'';
ok(@projectNames,'Verified behavior: getProjectNames returns '.$projectNames[0].$tmp);

describeProject();
$tmp = $error?$error:'';
ok(@projectDescription,'Verified behavior: describeProject returns '.$projectDescription[0].$error);

loadProjectDetails('4x56');
$tmp = $error?$error:'';
ok(%projectDetails,'Verified behavior: loadProjectDetails returns '.(keys %projectDetails)[0]." ".$error);
