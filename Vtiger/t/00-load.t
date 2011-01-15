#!perl -T

use lib 'lib';
use Test::More tests => 1;

BEGIN {
    use_ok( 'Vtiger' ) || print "Bail out!
";
}

diag( "Testing Vtiger $Vtiger::VERSION, Perl $], $^X" );
