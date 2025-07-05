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

fun main(){
var t: Int = readInt()
while(t-- > 0) solve()
}


fun solve(){
    var ans: StringBuilder = StringBuilder()
    var count: Int = 0

    var n: Int = readInt()
    var a = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    var b = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()

    for (i in 0..n-1) {
        if (a[i] > b[i]) {
            a[i] = a[i].xor(b[i])
            b[i] = a[i].xor(b[i])
            a[i] = a[i].xor(b[i])
            ans.append("3 ${i+1}\n")
            count++
        }
    }

    var noSwap: Boolean
    for (i in 1..n-1) {
        noSwap = true
        for(j in n-1 downTo i) {
            if (a[j] < a[j-1]) {
                a[j] = a[j].xor(a[j-1])
                a[j-1] = a[j].xor(a[j-1])
                a[j] = a[j].xor(a[j-1])

                ans.append("1 ${j}\n")
                count++
                noSwap = false
            }
        }
        if (noSwap) break
    }

    for (i in 1..n-1) {
        noSwap = true
        for(j in n-1 downTo i) {
            if (b[j] < b[j-1]) {
                b[j] = b[j].xor(b[j-1])
                b[j-1] = b[j].xor(b[j-1])
                b[j] = b[j].xor(b[j-1]) 
                ans.append("2 ${j}\n")
                count++
                noSwap = false
            }
        }
        if (noSwap) break
    }

    output{
        println(count)
        print(ans)
    }
}