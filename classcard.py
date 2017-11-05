import math
import random

class Card():
    ranks=["Deuce","Trey","Four","Five","Six","Seven","Eight","Nine","Ten","Knave","Hag","Cowboy","Bullet"]
    suits=["Diamonds","Clubs","Hearts","Spades"]
    def __init__(self,num=0):
        self.number = num%52
    def num(self):
        return self.number%52
    def __hash__(self):
        return self.number%len(Card.ranks)
    def __lt__(self,other):
        return hash(self)<hash(other)

    def __gt__(self,other):
        return hash(self)>hash(other)
    def __le__(self,other):
        return hash(self)<=hash(other)
    def __ge__(self,other):
        return hash(self)>=hash(other)
    def rank(self):
        return Card.ranks[self.number%len(Card.ranks)]
    def suit(self):
        return Card.suits[self.number//len(Card.ranks)]
    def __eq__(self,other):
        return hash(self)==hash(other)
    def __str__(self):
        return self.rank()+ " of " +self.suit()
    def __repr__(self):
        return str(self)    
    def __gt__(self,other):
        return self.num()>other.num()
    def __lt__(self,other):
        return other>self
    def __ge__(self,other):
        return not self<other
    def __le__(self,other):
        return not self>other
    def isFace(self):
        return self.rank() in Card.ranks[-4::]
    def isAce(self):
        return self.rank()==Card.ranks[-1]
    def isBlack(self):
        return (self.number%len(Card.ranks))%2==1
    def isRed(self):
        return (self.number%len(Card.ranks))%2==0
class Hand():
    def __init__(self, card=None):
        self.cards=[]
        if card:
            self.cards.append(card)
    def __bool__(self):
        return bool(self.cards)
    def __lt__(self,other):
        return hash(self)<hash(other)

    def __gt__(self,other):
        return hash(self)>hash(other)
    def __le__(self,other):
        return hash(self)<=hash(other)
    def __ge__(self,other):
        return hash(self)>=hash(other)
    def addCard(self,card=None):
        if not card:
            card=Card(random.randint(0,51))
        self.cards.append(card)
        self.cards.sort()
    def multest(self):
        norpt=[]
        for i in self.cards:
            if i not in norpt:
                norpt.append(i)
        lnrpt=len(norpt)
        counter=[0]*lnrpt
        for i in range(5):
            for j in range(lnrpt):
                if self.cards[i]==norpt[j]:
                    counter[j]+=1
        return counter
    def isPair(self):
        sett=self.multest()
        return len(sett)==4
    def isTwoPair(self):
        sett=self.multest()
        return len(sett)==3 and 2 in sett
    def isThreeOfAKind(self):
        sett=self.multest()
        return len(sett)==3 and 1 in sett
    def isStraight(self):
        listy=[hash(card) for card in self.cards]
        listy.sort()
        minimum=min(listy)
        final=[k-minimum for k in listy]
        return final==list(range(len(self.cards)))
    def isThreeOfAKind(self):
        sett=self.multest()
        return len(sett)==3 and 1 in sett
    def isFlush(self):
        listy=[card.suit() for card in self.cards]
        return listy.count(listy[0])==5
    def isFullHouse(self):
        sett=self.multest()
    def isFourOfAKind(self):
        sett=self.multest()
        return len(sett)==2 and 4 in sett
    def isFiveOfAKind(self):
        sett=self.multest()
        return len(sett)==1
    def isStraightFlush(self):
        return self.isStraight() and self.isFlush()
    def trashCard(self):
        del self.cards[0]
        return self
    def __hash__(self):
        if self.isFiveOfAKind():
            return 9
        if self.isStraightFlush():
            return 8
        if self.isFourOfAKind():
            return 7
        if self.isFullHouse():
            return 6
        if self.isFlush():
            return 5
        if self.isStraight():
            return 4
        if self.isThreeOfAKind():
            return 3
        if self.isTwoPair():
            return 2
        if isPair():
            return 1
        else:
            listy=[hash(k) for k in self.cards]
            maximum=max(listy)
            return maximum-13
    def __str__(self):
        if not self:
            return "Hand is Empty"
        return str(self.cards)[1:-1]
    def __repr__(self):
        return str(self)

class Shoe():
    def __init__(self,numDecks=1):
        self.cards=[Card(k) for k in range(52*numDecks)]
        self.numDecks=numDecks
    def __str__(self):
        return str(self.numDecks)+"-deck Shoe of " + str(len(self.cards)) + " cards"
    def __repr__(self):
        return str(self)
    def shuffle(self):
        random.shuffle(self.cards)
    def drawCard(self):
        return self.cards.pop()
    def dealHand(self, deal=1):
        hand=Hand()
        for k in range(deal):
            hand.addCard(self.drawCard())
        return hand
    def dealTable(self, hands=1, deal=1):
        table=[self.dealHand(deal) for k in range(hands)]
        for i in range(deal-1):
            for k in table:
                k.addCard(self.drawCard())
        return table

