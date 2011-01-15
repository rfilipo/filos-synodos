#
#===============================================================================
#
#         FILE:  01-basic.t
#
#  DESCRIPTION:  basic functions
#
#        FILES:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  1.0
#      CREATED:  11-01-2011 13:29:59
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;

use lib 'lib';
use Test::More;                    

my $number_of_tests_run = 0;

use Vtiger;


my $url      = 'http://127.0.0.1/vtiger/webservice.php';
my $vt       = new Vtiger($url);
my $username = 'admin';
my $pin      = 'xBNhY4gLb9lnp2k2';

my $vtsession  = $vt->getSession($username, $pin);
my $session    = $vtsession->{'sessionName'};

####################################
ok($vtsession, 'Ok session 
sessionName  : '.$vtsession->{'sessionName'}.'
userId       : '.$vtsession->{'userId'}.' 
version      : '.$vtsession->{'version'}.' 
vtigerVersion: '.$vtsession->{'vtigerVersion'}.' 
');
$number_of_tests_run++;
    
my $modules = $vt->listModules($session);

foreach my $module(@{$modules->{'types'}}){
  my @desc  = $vt->describe($session,$module);
  
  ##############################################
  ok($desc[0], 'Ok module: '.$desc[0]->{'name'});
  $number_of_tests_run++;

  foreach my $d (@{$desc[0]->{'fields'}}){
   
    ##############################################################
    ok($d, 'Ok '.$desc[0]->{'name'}.' description: '.$d->{'name'});
    $number_of_tests_run++;

  }
}

# With a 'Session Id' string and the modules description 
# we can perform all service functions: 

my $contacts  = $vt->query($session,"select * from Contacts;"); 

##############################################################
ok($contacts, 'Ok query'.$contacts);
$number_of_tests_run++;

done_testing( $number_of_tests_run );
