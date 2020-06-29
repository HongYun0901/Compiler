/* Hello World Example */
object HelloWorld {
  def main () {
    // Print text to the console
    println ("Hello World")
    var a:int = 5
    if (a==5)
    {
      a = 6
      println("if 2_1 a==5")
      if (a==4)
        println("if 3_1 a==4")
      else
        println("else 3_1 a!=4")
    }
    else
    {
      println("else 2_1 a!=5")
    }

    if (a==5)
    {
      a = 4
      println("if 2_2 a==5")
    }
    else
    {
      println("else 2_2 a!=5")
    }

  

    while (a>0)
    //for (a <- a to 10)
    {
        var b:int
      b = 3
      while (b>0)
      //for(b <- b to 6)
      {
        print("*")
        b = b - 1
      }
      println("")
      a = a - 1
    }
  }
}