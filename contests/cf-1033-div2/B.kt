import java.util.StringTokenizer
import java.io.PrintWriter
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main() {
    var t: Int = readInt()
    
    while(t-- > 0) {
        solve()
    }
}

fun solve() {
    var n: Int = readInt()
    var s: Int = readInt()

    var ans: Int = 0

    for (i in 1..n){
        var arr: IntArray = readLine()!!.split(" ").map{it.toInt()}.toIntArray()

        if (arr[0] == arr[1] && arr[2] == arr[3]) {
            ans++
            continue
        }
        
        if (arr[0] != arr[1] && arr[2] + arr[3] == s) {
            ans++
        }
    }

    println(ans)
}