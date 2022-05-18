object first {
def  main(args: Array[String]){
		val list = List("Hello here PICT PICT is twice","Hello World")
		val words = list.flatMap(line => line.split(" "))
		val mapwords = words.map(word => (word,1))
		val groupedData = mapwords.groupBy(_._1)
		val result = groupedData.mapValues(list=>{
			list.map(_._2).sum
			})
		result.foreach(println)
	}
}
