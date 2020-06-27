/* Sigma.scala
 *
 * Compute sum = 1 + 2 + ... + n
 */

object sigma
{
  // constants and variables
  val n = 10
  val str = "sadasd"
  var sum: int
  var index: int


  def fib(n:int):int {
    if(n<2)
      return n
    //else
      return fib(n-1) + fib(n-2)
  }

  def main () {
    sum = 1
    index = 0
    val str = "string haha"
    println(str)
    print ("The sum is")
    println (sum)
    println(index)
    var i = 0
    if(i <= 0){
      println("i <= 0")
      if(sum == 0 ){
        println("sum=0")
      }
      else{
        println("sum!=0")
      }
    }
    else if (i>=0){
      println("i>=0")
    }
    else{
      println("i!= 1 or 0 ")
    }
    for(sum <- 10 to 10){
      println(index)
      index = index + 1
      for(i <- 0 to 10){
        print(i)
        index = index + 1
      }
      println("")
    } 
    println(index)
    i = 0
    for(i <- 0 to 10){
      println(fib(i))
    }
  
  }
}
