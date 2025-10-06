import os
import random
import re
import sys

DAMPING = 0.85
SAMPLES = 10000


def main():
   
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    
    corpus = crawl(sys.argv[1])
    ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    print(f"PageRank Results from Sampling (n = {SAMPLES})")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")


def crawl(directory):
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """

    pd=dict()

    if corpus[page] is not None:
        numberOfLinks=len(corpus[page])

        probabLikable=damping_factor/numberOfLinks #the probability of getting selected by 0.85 gets distributed equally among each link, excluding itself
        probabUnlikable=(1-damping_factor)/(len(corpus)) #the probability of getting selected by 0.15 gets distributed equally among all pages in corpus

        for one in corpus:
            if one in corpus[page]:
                pd[one]=probabLikable+probabUnlikable
            else:
                pd[one]=probabUnlikable

    else:
        for one in corpus:
            pd[one]=1/len(corpus)
        
    return pd

        
    

def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    sampleResult=dict()

    page=random.choice(list(corpus.keys()))

    pageCount=1

    while (pageCount!=n):

        sampleResult[page]=sampleResult.get(page, 0)+1
        pd=transition_model(corpus, page, damping_factor)
        page=random.choices(list(pd.keys()), weights=pd.values())[0] #pd has key-value pair for a page and probability of it getting selected
        pageCount+=1

    #calculating final probabilities
    
    for each in sampleResult:
        sampleResult[each]/=n #dividing the total number of samplings to get the probability

    return sampleResult




def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    

    result=dict()
    prevResult=dict()
    dictForKeepingCheck=dict()


    def DifferenceIsSmall(): #checks if the previous result and current result have minimal difference
        count=0
        for each in result:
            if abs(result[each]-prevResult[each])<=0.001:
                count+=1
        return count==len(result)
    


    for one in corpus: #initializing 
        result[one]=1/len(corpus)

        for each in corpus: #adding pages that link to other pages
            if each in corpus[one]:
                dictForKeepingCheck[each]=dictForKeepingCheck.get(each, set()) | {one}
    
    N=len(corpus)


    while(True):
        
        prevResult=result.copy()

        for one in corpus:
            firstPart=(1-damping_factor)/len(corpus)
            secondPart=0

            for each in dictForKeepingCheck[one]:

                if len(corpus[each])!=0:
                    secondPart+=result[each]/len(corpus[each])
                else:
                    secondPart+=result[each]/len(corpus) #page having no link is interpreted as having links to all including itself
                
            result[one]=firstPart+damping_factor*secondPart
        
        if DifferenceIsSmall():
            break
        

    return result
                
            

    
    


if __name__ == "__main__":
    main()
