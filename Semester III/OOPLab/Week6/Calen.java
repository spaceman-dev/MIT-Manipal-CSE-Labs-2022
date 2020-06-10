import java.util.Scanner;
import java.util.Calendar;  
import java.util.*; 
  
class Calen { 
  
    // Driver code 
    public static void main(String[] args) 
    { 
        // creating a calendar 
        Calendar c = Calendar.getInstance(); 
  
        // get the value of HOUR field 
        System.out.println("Hour : " + c.get(Calendar.HOUR)); 
  
        // get the value of MINUTE field 
        System.out.println("Minute : " + c.get(Calendar.MINUTE)); 
  
        // get the value of SECOND field 
        System.out.println("Second : " + c.get(Calendar.SECOND)); 
  
        // get the value of AM_PM field 
        System.out.println("AM or PM : " + c.get(Calendar.AM_PM)); 
  
        // get the value of HOUR_OF_DAY field 
        System.out.println("Hour (24-hour clock) : " + c.get(Calendar.HOUR_OF_DAY)); 
        // get the value of DATE_OF_WEEK field 
        System.out.println("Day of week : " +  
                        c.get(Calendar.DAY_OF_WEEK)); 
                          
    // get the value of DAY_OF_YEAR field 
    System.out.println("Day of year : " + 
                        c.get(Calendar.DAY_OF_YEAR)); 
                          
    // get the value of WEEK_OF_MONTH field 
    System.out.println("Week in Month : " +  
                        c.get(Calendar.WEEK_OF_MONTH)); 
                          
    // get the value of WEEK_OF_YEAR field 
    System.out.println("Week in Year : " +  
                        c.get(Calendar.WEEK_OF_YEAR)); 
  
                      
    // get the value of DAY_OF_WEEK_IN_MONTH field 
    System.out.println("Day of Week in Month : " + 
                        c.get(Calendar.DAY_OF_WEEK_IN_MONTH)); 
     // get the value of DATE field 
    System.out.println("Day : " + 
                        c.get(Calendar.DATE)); 
      
    // get the value of MONTH field 
    System.out.println("Month : " + 
                        c.get(Calendar.MONTH)); 
                      
    // get the value of YEAR field 
    System.out.println("Year : " +  
                        c.get(Calendar.YEAR)); 

    } 
} 