/*
 * Example with Functions
 */

object example {
  val a = 5 + 3 *4
  var x:boolean = true
  var c = 1 < 3

  // function declaration
  def add (a: int, b: int): int 
  {
    
    return a+b
  }

  def test(a:string, b:char,c:boolean){
     var z = 3
     c = 4
     c = z
     return 
  }


  
  def main()
  {
    var c:int
    var b:float 
    val a = 3
    c = c - b
    val x:char = 'x'
    c = add(a, 10)
    var zz = test("123",'c',true)


    if ( c < 5){
      c = 4
      if(true) {
        c =7
        if(false){
          c = 9
        }
        else if (false){
          a = a + a
        }
      }
      else{
        c=99
      }
      var asdasd:int
        
      
    }
    else if(c>10) {
      c = 5
    }
    else if(c> 2){
      c = 3
    }
    else if ( c > 3){
      c = 2
    }
    else {
      c = 5
    }

    a=3
    

    

    
  }


}
