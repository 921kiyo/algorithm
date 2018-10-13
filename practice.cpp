unsigned long normalise(unsigned long input_time)
 {
 
     // This produces a formatted time string like:
     // Thu_Nov_24_18:22:48_1986
     string str_time = format_time( input_time );

     if input_time == 0{
         return str_time;
     }
 
     while( str_time.substr(1,3) != "Sun")
     {
         input_time -= 24*60*60;
         str_time = format_time( input_time );
     }
 
     while( str_time.substr(11,2) != "00" )
     {
         input_time -= 60*60;
         str_time = format_time( input_time );
     }
 
     while( str_time.substr(14,2) != "00")
     {
         str_time = format_time( input_time );
         input_time -= 60;
     }
 
     while( str_time.substr(17,2) != "00")
     {
         input_time -= 1;
         str_time = format_time( input_time );
     }
 
     return input_time;
 }