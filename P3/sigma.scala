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
    
    while (index <= 10) {
      sum = sum + index
      index = index + 1
    }
    print ("The"" sum"" is")
    println (sum)
    println(index)
    var i 
    for(sum <- 1 to 10){
      index = index + 1
      for(i <- sum to 10){
        index = index + 1
      }
    }
  }
}
