using System;

 public class runme {
     static void Main() {


	//string rohi=rijndael.enc("rohit","hey rohit anurag");
        // Console.WriteLine(rijndael.enc("rohit","hey rohit anurag"));
	        // string roi=rijndael.dec("rohit",rohi);
	            //System.Console.WriteLine(rohi);
		string ciph = rijndael.encd("password", "Some random text to test the encoding-decoding of this AES library.");
		System.Console.WriteLine(ciph);
		System.Console.WriteLine(("password", ciph);
		System.Console.WriteLine(rijndael.decd("password", rijndael.encd("password", "Some random text to test the encoding-decoding of this AES library.")));


 }
}
