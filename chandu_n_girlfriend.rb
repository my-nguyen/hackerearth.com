# this solution fails test inputs #7, #8, and #9 of the 9 test inputs
def imprimer(array)
  array.each do |element|
    print("#{element} ")
  end
  puts
end

def sort(array)
  if (array.length <= 1)
    return array
  else
    pivot = array.shift
    lower = []
    i = 0
    while (i < array.length)
      if (array[i] > pivot)
        # copy the smaller element to the "lower" array
        lower << array[i]
        # remove the smaller element from current array
        array.delete_at(i)
      else
        i += 1
      end
    end

    # assemble the lower, pivot and upper parts. Note the recursive calls
    array = sort(lower) + [pivot] + sort(array)
    return array
  end
end

case_count = gets.to_i
case_count.times do
  array_size = gets.to_i
  array = gets.scan(/\d+/).map(&:to_i)
  imprimer(sort(array))
end
