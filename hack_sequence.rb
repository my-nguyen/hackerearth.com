require 'benchmark'

def hack2 i
  one = 1
  two = 1
  n = 1
  3.upto(i) do
    n = 2014*two + 69*one
    one = two
    two = n
  end
  n % (10**9 + 7)
end

class MyClass
  attr_reader :hack
  def initialize
    @hack = []
    @hack << (one = 1)
    @hack << (two = 1)
    3.upto(1000000000000000) do
      @hack << (three = 2014*two + 69*one)
      one = two
      two = three
    end
  end
end

time = Benchmark.realtime do
  obj = MyClass.new
  divider = 10**9 + 7
  gets.to_i.times do
    time = Benchmark.realtime do
      puts (obj.hack[gets.to_i+1] % divider)
    end
  end
end
temps = time.to_i
puts "Setup time: #{temps/60} minutes #{temps%60} seconds"
