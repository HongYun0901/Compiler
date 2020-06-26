/*
 * Example with Functions
 */

object example {
  //val a = 5
  var a
  var c

  // function declaration
  def add (a: int, b: int): int 
  {
    var c
    return a+b
  }


  
  def main()
  {
    var c:int
    a = 5
    c = add(a, 10)
    if (c > 10)
      print -c
    else
      print c
    println ("Hello World")

    
  }


}
