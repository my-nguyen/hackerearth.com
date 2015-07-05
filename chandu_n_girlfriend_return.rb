# solution passed all 9 input test cases
def myprint(array)
  array.each do |element|
    print("#{element} ")
  end
  puts
end

def merge_sorted_arrays(array1, array2)
  one = two = three = 0
  array3 = []
  while (one < array1.length && two < array2.length)
    if array1[one] > array2[two]
      array3[three] = array1[one]
      one += 1
    else
      array3[three] = array2[two]
      two += 1
    end
    three += 1
  end

  while one < array1.length
    array3[three] = array1[one]
    one += 1
    three += 1
  end
  while two < array2.length
    array3[three] = array2[two]
    two += 1
    three += 1
  end

  array3
end

case_count = gets.to_i
case_count.times do
  arrays_size = gets.split.map {|i| i.to_i}
  array1 = gets.split.map {|i| i.to_i}
  array2 = gets.split.map {|i| i.to_i}
  myprint(merge_sorted_arrays(array1, array2))
end
