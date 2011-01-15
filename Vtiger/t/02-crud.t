#
#===============================================================================
#
#         FILE:  02-crud.t
#
#  DESCRIPTION:  CRUD actions
#
#        FILES:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  1.0
#      CREATED:  11-01-2011 17:14:41
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

my $session  = $vt->getSession($username, $pin);

####################################
ok($session, 'Ok session '.$session->{'sessionName'});
$number_of_tests_run++;

# CREATE
# create a new contact
   my $ctcData       = {
        'assigned_user_id'=> $session->{'userId'},
        'lastname'        => 'Filipo',
       };

my $newContact = $vt->create($session->{'sessionName'},'Contacts',$ctcData);
my $contactId = $newContact->{'id'};
##################################################
ok($newContact, 'Ok create contact '.$newContact->{'id'});
$number_of_tests_run++;

# RETRIEVE
my $retrieved =$vt->retrieve($session->{'sessionName'}, $contactId);
##################################################
ok($retrieved, 'Ok retrieve contact '.$retrieved->{'lastname'});
$number_of_tests_run++;


# UPDATE
$retrieved->{'lastname'} = "Filapo";
my $updated =$vt->update($session->{'sessionName'},$retrieved);
##################################################
ok($updated, 'Ok update contact '.$updated->{'lastname'});
$number_of_tests_run++;

# DELETE
my $deleted =$vt->delete($session->{'sessionName'}, $contactId);
##################################################
ok($deleted, 'Ok delete contact: '.$deleted);
$number_of_tests_run++;


done_testing( $number_of_tests_run );
