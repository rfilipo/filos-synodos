#!/usr/bin/perl
#===========================================================================
#
#         FILE:  vtiger.pl
#
#        USAGE:  ./vtiger.pl
#
#  DESCRIPTION:  conecta o vtiger via json rpc
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Ricardo Filipo (rf), ticardo.filipo@gmail.com
#      COMPANY:  Mito-Lógica design e soluções de comunicação ltda
#      VERSION:  0.1.28
#      CREATED:  29-12-2010 14:41:09
#     REVISION:  ---
#===========================================================================

use Config::Constants xml => 'config/config.xml';
use strict;
use warnings;


use lib 'Vtiger/lib';
use Vtiger;
use Config::Constants qw/USER_NAME ACCESS_KEY VTIGER_URL/;

our $VERSION = '0.1.28';

our $vt =  new Vtiger(VTIGER_URL);

# glue vars
our $vterror;
our $session;       # session name
our $vtsession;
our @projectNames;
our @projectDescription;
our %projectDetails;


# init environment

# do things
# system('scripts/httpd.pl');

# glue functions
##############################################

sub getSession {
    my $username = USER_NAME;
    my $pin      = ACCESS_KEY;

    $vtsession  = $vt->getSession($username, $pin);
    $session    = $vtsession->{'sessionName'};
    return $session;
}

sub getProjectNames {
    my $session = shift;
    my $projects = [];

    local $SIG{'__DIE__'} =
    sub {
        $vterror =  'uh .. oh ... '. $_[0];
        push(@projectNames, "No Projects\n$vterror");
    };

    eval {$projects = $vt->query($session, "select name from Projects")};
    foreach my $project (@{$projects}) {
        push(@projectNames, $project-> {'name'});
    }

    if (!@projectNames) {
        push(@projectNames, 'No Projects');
    }
    return @projectNames;
}

sub getContacts {
    return $vt->query($session,"select * from Contacts");
}

sub getAccounts {
    return $vt->query($session,"select * from Accounts");;
}

sub getProjects {
    return $vt->query($session,"select * from Projects");
}

sub createProject {
    my $name = shift;
    print "Sessao: $session\n";
    my $newPrj;

    my $prjData = {
        'assigned_user_id'=> $session->{'userId'},
        'name'            => $name
        };

    local $SIG{'__DIE__'} =
    sub {
        $vterror = 'uh .. oh ... '. $_[0];
        $projectDetails{'info'} = 'No Details';
        $projectDetails{'error'} = $vterror;
    };
    eval {
    $newPrj = $vt->create(
         $session->{'sessionName'},
         'Projects',
         $prjData
     )
    };
     %projectDetails = $newPrj;
}

=head1 loadProjectDetails

 %projectDetails = (
                       "projectname"             =>  "O projeto",
                       "startdate"               =>  localtime,
                       "targetenddate"           =>  "12345",
                       "actualenddate"           =>  "12345",
                       "projectstatus"           =>  "plan",
                       "projecttype"             =>  "",
                       "linktoaccountscontacts"  =>  "Inez Oliveira",
                       "assigned_user_id"        =>  "1",
                       "project_no"              =>  "123",
                       "targetbudget"            =>  "300",
                       "projecturl"              =>  "http://www.ffff.com",
                       "projectpriority"         =>  "urgent",
                       "progress"                =>  "plan",
                       "createdtime"             =>  "123456",
                       "modifiedtime"            =>  "123456",
                       "description"             =>  "bla bla bla",
                       "id"                      =>  "0",
                   );

=cut


sub loadProjectDetails {
    my $projectId = shift;
    print "Sessao: $session\n";

    local $SIG{'__DIE__'} =
    sub {
        $vterror = 'uh .. oh ... '. $_[0];
        $projectDetails{'info'} = 'No Details';
        $projectDetails{'error'} = $vterror;
    };
    eval { %projectDetails = $vt->retrieve($session, $projectId)};
}

##################################################

sub listModules {
    my $sessionId = shift;
    my $res = $vt->listModules($sessionId);
    return $res->{types};
}

sub describeProject {
    print "Sessao: $session\n";
    @projectDescription = $vt->describe($session, 'Project');
}


1;
#END
####################################################
