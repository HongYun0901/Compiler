/* Sigma.scala
 *
 * Compute sum = 1 + 2 + ... + n
 */

object Sigma
{
  // constants and variables
  //val n = 10
  //val str = "sadasd"
  var sum: int
  var index: int

  def main () {
    sum = 0
    index = 0
    print ("The sum is")
    println (sum)
    println(index)
    var i
    for(sum <- 10 to 10){
      println(index)
      index = index + 1
      for(i <- 0 to 10){
        print(i)
        index = index + 1
      }
      print("\n")
    } 
    println(index)

  }
}
