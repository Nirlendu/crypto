/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class rijndael {
  public static string enc(string password, string filename) {
    string ret = rijndaelPINVOKE.enc(password, filename);
    return ret;
  }

  public static string dec(string password, string filename) {
    string ret = rijndaelPINVOKE.dec(password, filename);
    return ret;
  }

  public static string enc_dec(string password, string filename) {
    string ret = rijndaelPINVOKE.enc_dec(password, filename);
    return ret;
  }

}