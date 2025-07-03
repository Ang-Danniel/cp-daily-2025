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

val mod: Long = 1000_000_007;
val listOfInv = MutableList<Long>(100_001) {index -> index.toLong()}
val listOfFact = MutableList<Long>(100_001) {index -> index.toLong()}


fun main(){
var t: Int = readInt()


listOfFact[0] = 1L
listOfInv[0] = 1L
for (i in 1..100_000) {
    listOfFact[i] *= listOfFact[i-1]
    listOfFact[i] %= mod

    listOfInv[i] = inv(listOfFact[i])
}
while(t-- > 0) solve()
}

fun solve(){
    var a: Long = readLong()
    var b: Long = readLong()
    var k: Long = readLong()

    var row: Long = ((a - 1L) * k) % mod
    row++

    var col: Long = k * (b - 1L)
    col %= mod

    var st = (row-a) + 1L

    for(i in st..row){
        col *= i
        col %= mod
    }

    col *= listOfInv[a.toInt()]
    col %= mod

    col++
    col %= mod

    if (col < 0) col += mod

    output{
        println("${row} ${col}")
    }
}

fun inv(a: Long): Long{
    return if (a <= 1L) a else mod - (mod/a) * inv(mod % a) % mod
}
// 299929959 603196135