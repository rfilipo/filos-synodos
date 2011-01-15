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
#      VERSION:  1.0
#      CREATED:  29-12-2010 14:41:09
#     REVISION:  ---
#===========================================================================

use Config::Constants xml => 'config/config.xml';
use strict;
use warnings;

# glue vars
our $session;
our @project_name;
our @project_description;
our %project_details;


# init environment

# do things



#END
####################################################
use lib 'Vtiger/lib';
use Vtiger;
use Config::Constants qw/USER_NAME ACCESS_KEY VTIGER_URL/;

our $VERSION = '0.1.1'

our vt =  new Vtiger(VTIGER_URL);

##############################################

sub login {
   my $un = shift;
   my $ak = shift;
   print "efetuando login ... como $un -> $ak\n";
   my $req = HTTP::Request->new(POST => VTIGER_URL);
   $req->content_type('application/x-www-form-urlencoded');
   $req->content('operation=login&username='.$un.'&accessKey='.$ak);

# Pass request to the user agent and get a response back
   my $res = $ua->request($req);
   my $jsonResponse = {};
   if ($res->is_success) {
      $jsonResponse = $json->decode($res->content);
      die ('Falhou o login!!! '.$jsonResponse->{error}) unless $jsonResponse->{'success'} eq 'true';
      return sessionId => $jsonResponse->{result}{sessionName};
   }
}


##############################################

sub getSession{
   # The login process need a challenge hash and a access key
   my $req = HTTP::Request->new(GET => VTIGER_URL.'?operation=getchallenge&username=admin');
   my $res = $ua->request($req);

   print USER_NAME.'  '.ACCESS_KEY."\n";

   my $challenge = {};
   if ($res->is_success) {
       $challenge = $json->decode($res->content);
       # the md5 digested access key
       $ctx->add($challenge->{result}{token}.ACCESS_KEY);
       my $ak = $ctx->hexdigest;
       my $un = USER_NAME;
       $session = login($un, $ak);
   }else {
       die $res->status_line, "\n";
   }
}

##################################################

sub loadProjects{
    #my $self = shift;
    my $session = shift;
    print "Usando sessão: $session\n";
    @project_name = ("Projeto 1", "Projeto 2", "Projeto 3", "Projeto 3", "Projeto 3", "Projeto 3", "Projeto x ...");
}

sub getProjects{
    return query($session, "select * from Projects");
}

sub getContacts{
    return query($session,"select * from Contacts");
}

sub getAccounts{
    return query($session,"select * from Accounts");;
}

##################################################

sub loadProjectDetails{
    my $id = shift;
    print "Sessao: $session\n";
    %project_details = retrieve($session, 'Project');

    print "Carregando projeto id: $id\n";
    return %project_details;
    %project_details = (
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
}

##################################################

sub listModules {
   my $sessionId = shift;
   my $req = HTTP::Request->new(GET => VTIGER_URL.'?sessionName='.$sessionId.'&operation=listtypes');
   my $res = $ua->request($req);

   my $jsonResponse = {};
   if ($res->is_success) {
      $jsonResponse = $json->decode($res->content);
      die ('Falhou o list!!! '.$jsonResponse->{error}) unless $jsonResponse->{'success'} eq 'true';
      return $jsonResponse->{result}{types};
   }
}

sub describeProject{
    print "Sessao: $session\n";
    @project_description = describe($session, 'Project');
}


##################################################

sub describe {
   my $sessionId = shift;
   my $module    = shift;
   my $params    = '?sessionName='.$sessionId.'&elementType='.$module.'&operation=describe';
   return getVtiger($params);
}

sub create {
   my $sessionId     = shift;
   my $moduleName    = shift;
   my $userId        = shift;
   my $lastName      = shift;
   %contactData      = (
        'lastname'        => $lastName,
        'assigned_user_id'=> $userId
        );
   my $objectJson    = json->;
   my $params        = {(
        "sessionName"=>$sessionId,
        "operation"=>'create',
        "element"=>$objectJson,
        "elementType"=>$moduleName
        )};
   return postVtiger($params);
}

sub delete {
   my $sessionId = shift;
   my $module    = shift;
   my $params    = '?sessionName='.$sessionId.'&elementType='.$module.'&operation=describe';
   return getVtiger($params);
}

sub update {
   my $sessionId = shift;
   my $module    = shift;
   my $params    = '?sessionName='.$sessionId.'&elementType='.$module.'&operation=describe';
   return getVtiger($params);
}

sub query{
    my $sessionId = shift;
    my $query = shift;
    my $params='?sessionName='.$sessionId.'&operation=query&query='.$query;
    return getVtiger($params);
}

sub retrieve {
   my $sessionId = shift;
   my $id    = shift;
   my $params = '?sessionName='.$sessionId.'&operation=retrieve&id='.$id;
   return getVtiger($params);


# this is trash
   my $req = HTTP::Request->new(GET => VTIGER_URL.$params);
   my $res = $ua->request($req);

   my $jsonResponse = {};
   if ($res->is_success) {
      $jsonResponse = $json->decode($res->content);
#use Data::Dumper;
#print Dumper ($jsonResponse->{error});
       die ('Falhou o describe: '.$jsonResponse->{error}{message}) unless $jsonResponse->{'success'} eq 'true';
      return $jsonResponse->{result};
      my $description = describe($session->{sessionId}, 'Project');

#print Dumper ($description);
      foreach my $field(@{$description->{fields}}){
          print $field->{name}."\n";
      }
      return @{$description->{fields}}
   } else {
      die("Erro ao conectar servidor\n");
   }
}

sub getVtiger{
   my $params = shift;
   my $req = HTTP::Request->new(GET => VTIGER_URL.$params);
   my $res = $ua->request($req);

   my $jsonResponse = {};
   if ($res->is_success) {
      $jsonResponse = $json->decode($res->content);
      die ('Service fault! '.$jsonResponse->{error}{message}."\nurl: ".VTIGER_URL.$params) unless $jsonResponse->{'success'} eq 'true';
      return $jsonResponse->{result};
   } else {
      die("Connection error\n");
   }
}
