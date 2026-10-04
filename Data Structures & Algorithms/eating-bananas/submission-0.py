class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def totalHours(hr: int) -> int:
            hours = 0
            for p in piles:
                hours += math.ceil(p / hr)
            return hours
        
        low = 1
        high = max(piles)
        ans = high
        
        while low <= high:
            mid = low + (high - low) // 2
            
            if totalHours(mid) <= h:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans

        