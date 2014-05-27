public class main {
   public static void main(String argv[]) {
     System.loadLibrary("rijndael");
    String hello = rijndael.enc("rohit","hey");
        System.out.println(rijndael.enc("rohit","hey"));

System.out.println(rijndael.dec("rohit", "Yj4ErwheWivTPDZskAFEbg=="));
         
   }
 }
