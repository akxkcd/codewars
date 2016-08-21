

def find_missing(sequence):
   seq_length = len(sequence)
   diff = (sequence[-1] - sequence[0])/seq_length
   low = 0
   high = len(sequence)-1
   while high>=low:
      mid = (high+low)/2
      if sequence[mid+1] - sequence[mid] != diff:
         return sequence[mid] + diff
      if mid>0 and sequence[mid]-sequence[mid-1] != diff:
         return sequence[mid-1] + diff
     
      if sequence[mid] == sequence[0] + mid*diff:
         low = mid+1
      else:
         high = mid-1


print find_missing([2, 4, 8, 10, 12, 14])
print find_missing([1, 6, 11, 16, 21, 31])
