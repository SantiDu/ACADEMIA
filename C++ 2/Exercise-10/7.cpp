// a. no exception.
//      123456789
// b. statement 2 throws Exception3 exception.
//      12C9
// c. statement 4 throws Exception2 exception.
//      1234B89
// d. statement 6 throws Exception1 exception.
//      123456AD9
// e. statement 8 throws an unknown exception.
//      12345678


try {
    statement 1;
    statement 2;
    try {
        statement 3;
        statement 4;
        try {
            statement 5;
            statement 6;
        }
        catch(Exception1 & e1 ) {
            statement A;
            throw;
        }
        statement 7;
    }
    catch(Exception2 & e2) {
        statement B;
    }
    statement 8;
}
catch(Exception3 & e3) {
    statement C;
}
catch(Exception1 & e4) { 
    statement D; 
}
statement 9;