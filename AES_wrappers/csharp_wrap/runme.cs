using System;

 public class runme {
     static void Main() {

		System.Console.WriteLine("\nThese are the outputs of teh test:-\n");
		string ciph = rijndael.encd("password", "Some random text to test the encoding-decoding of this AES library.");
		System.Console.WriteLine(ciph);
		System.Console.WriteLine(rijndael.decd("password", ciph));
		System.Console.WriteLine(rijndael.decd("password", rijndael.encd("password", "Some random text to test the encoding-decoding of this AES library.")));
 }
}
