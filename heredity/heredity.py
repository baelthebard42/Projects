import csv
import itertools
import sys

PROBS = {

    # Unconditional probabilities for having gene
    "gene": {
        2: 0.01,
        1: 0.03,
        0: 0.96
    },

    "trait": {

        # Probability of trait given two copies of gene
        2: {
            True: 0.65,
            False: 0.35
        },

        # Probability of trait given one copy of gene
        1: {
            True: 0.56,
            False: 0.44
        },

        # Probability of trait given no gene
        0: {
            True: 0.01,
            False: 0.99
        }
    },

    # Mutation probability
    "mutation": 0.01
}


def main():

    # Check for proper usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python heredity.py data.csv")
    people = load_data(sys.argv[1])

    # Keep track of gene and trait probabilities for each person
    probabilities = {
        person: {
            "gene": {
                2: 0,
                1: 0,
                0: 0
            },
            "trait": {
                True: 0,
                False: 0
            }
        }
        for person in people
    }

    # Loop over all sets of people who might have the trait
    names = set(people)
    for have_trait in powerset(names):

        # Check if current set of people violates known information
        fails_evidence = any(
            (people[person]["trait"] is not None and
             people[person]["trait"] != (person in have_trait))
            for person in names
        )
        if fails_evidence:
            continue

        # Loop over all sets of people who might have the gene
        for one_gene in powerset(names):
            for two_genes in powerset(names - one_gene):

                # Update probabilities with new joint probability
                p = joint_probability(people, one_gene, two_genes, have_trait)
                update(probabilities, one_gene, two_genes, have_trait, p)

    # Ensure probabilities sum to 1
    normalize(probabilities)

    # Print results
    for person in people:
        print(f"{person}:")
        for field in probabilities[person]:
            print(f"  {field.capitalize()}:")
            for value in probabilities[person][field]:
                p = probabilities[person][field][value]
                print(f"    {value}: {p:.4f}")


def load_data(filename):
    """
    Load gene and trait data from a file into a dictionary.
    File assumed to be a CSV containing fields name, mother, father, trait.
    mother, father must both be blank, or both be valid names in the CSV.
    trait should be 0 or 1 if trait is known, blank otherwise.
    """
    data = dict()
    with open(filename) as f:
        reader = csv.DictReader(f)
        for row in reader:
            name = row["name"]
            data[name] = {
                "name": name,
                "mother": row["mother"] or None,
                "father": row["father"] or None,
                "trait": (True if row["trait"] == "1" else
                          False if row["trait"] == "0" else None)
            }
    return data


def powerset(s):
    """
    Return a list of all possible subsets of set s.
    """
    s = list(s)
    return [
        set(s) for s in itertools.chain.from_iterable(
            itertools.combinations(s, r) for r in range(len(s) + 1)
        )
    ]


def joint_probability(people, one_gene, two_genes, have_trait):
    """
    Compute and return a joint probability.

    The probability returned should be the probability that
        * everyone in set `one_gene` has one copy of the gene, and
        * everyone in set `two_genes` has two copies of the gene, and
        * everyone not in `one_gene` or `two_gene` does not have the gene, and
        * everyone in set `have_trait` has the trait, and
        * everyone not in set` have_trait` does not have the trait.
    """
    result=1 #initializing final result

    for each in people:

        gene_num=( 
            2 if each in two_genes else
            1 if each in one_gene else
            0
        )

        trait = each in have_trait #boolean value

        mother=people[each]['mother']
        father=people[each]['father']

        if mother is None or father is None: #no parents case
        
            prob=PROBS['gene'][gene_num]

         
        else: #yes parents case

            inheriting_probs={mother: 0, father:0} 


            for one in inheriting_probs:

                if one in one_gene:
                    inheriting_probs[one]=0.5 # 0.5 probability of giving a gene to child if it has one bad gene
                elif one in two_genes:
                    inheriting_probs[one]=1-PROBS["mutation"] # except for mutation there is a 100% chance that bad gene will be passed
                else:
                    inheriting_probs[one]=PROBS["mutation"] # if no bad gene there, it can only be transferred by mutation of a normal gene
            
            if gene_num==2:
                prob=inheriting_probs[mother]*inheriting_probs[father] # if two genes are present in child, one is from father, other is from mother
            elif gene_num==1:
                prob=inheriting_probs[mother]*(1-inheriting_probs[father]) + inheriting_probs[father]*(1-inheriting_probs[mother])
            else:
                prob=(1-inheriting_probs[father])*(1-inheriting_probs[mother])
            
        traitP=PROBS["trait"][gene_num][trait]

        result*=traitP*prob

    return result






def update(probabilities, one_gene, two_genes, have_trait, p):
    """
    Add to `probabilities` a new joint probability `p`.
    Each person should have their "gene" and "trait" distributions updated.
    Which value for each distribution is updated depends on whether
    the person is in `have_gene` and `have_trait`, respectively.
    """
    
    for each in probabilities:

        gene_num=(
            2 if each in two_genes else
            1 if each in one_gene else
            0
        )

        trait=each in have_trait #true if it is in have_trait

        probabilities[each]['gene'][gene_num]+=p #updating the dict with new probability distribution
        probabilities[each]['trait'][trait]+=p
        

def normalize(probabilities):
    """
    Update `probabilities` such that each probability distribution
    is normalized (i.e., sums to 1, with relative proportions the same).
    """
    for each in probabilities:

        geneTotal=0
        traitTotal=0

        geneTotal = sum(probabilities[each]['gene'][i] for i in range(3))
        traitTotal = sum(probabilities[each]['gene'][i] for i in range(3))

        for i in range(3):
            probabilities[each]['gene'][i]/=geneTotal
        
        for i in {True, False}:
            probabilities[each]['trait'][i]/=traitTotal



if __name__ == "__main__":
    main()
