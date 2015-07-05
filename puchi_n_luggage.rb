# this solution doesn't work
def myprint(lighters)
  lighters.each do |lighter|
    print("#{lighter} ")
  end
  puts
end

def qsort(array)
  if (array.length <= 1)
    return array
  else
    pivot = array.shift
    lower = []
    i = 0
    while (i < array.length)
      if (array[i] < pivot)
        # copy the smaller element to the "lower" array
        lower << array[i]
        # remove the smaller element from current array
        array.delete_at(i)
      else
        i += 1
      end
    end

    # assemble the lower, pivot and upper parts. Note the recursive calls
    array = qsort(lower) + [pivot] + qsort(array)
    return array
  end
end

def process(weights)
  tmp = qsort(weights.dup)
  weights.each do |weight|
    tmp.index(weight)
  end
end

case_count = gets.to_i
case_count.times do
  weight_count = gets.to_i
  weights = []
  weight_count.times do
    weights << gets.to_i
  end
  myprint(process(weights))
end
