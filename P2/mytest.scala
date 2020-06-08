object HelloWorld {
  val c:boolean = true
  def main(){
      var test = 3
        var a:int 
        var b:int[100]
        /*a = b[0]
		a = b[101]*/
		//val c:int[100]
  }


  var d:string = "qwr"
}


object Hibro {
  val c:boolean = true
  def main () {
    // Print text to the console
    val a:int = 5
    print ("Hello World")
    var f:float = 3.14
  }
  def HelloWorld(){
      var test = 3
  }

  var d:string = "qwr"
}
object axottest{

	val True = true

	var ba = true
	var bb:boolean = false
	var ia = 5
	var ib:int
	var ca = 'c'
	var sa = "is a string"

	val False = false
	var fabtable: int[100]

	def correct(s:string, c: char, i: int, b:boolean, test:int) : string
	{
	
		while(b){
			i = i + 1
			i = i - 1
			if(i < 5){
				i = i / 1
				i = i * 1
			}
			if(s == "" || s == s && !s != s){
				c = 'b'
			}
			else{
				c = 'c'
			}
		}
		
		for(i <- 5 to 10){
			b = true
			if(b >= true){
				b = false
			}
			if(i <= 9)
				i = 5
		}
		return s
	}

	def fab(n: int) : int
	{
		if(fabtable[n] != -1)
		{
			return fabtable[n]
		}
		return false
		if(n < 2)
		{ 
			fabtable[n] = n 
			return 3
		}
		else{
			fabtable[n] = fab(n-1) + fab(n-2)
		}
		return fabtable[n]
	}

	
	def main()
	{
		var i = 0
		for(i <- 0 to 99)
			fabtable[i] = -1

		sa = correct(sa, ca, ia, ba, ib)

		print(fab(50))
	}
}