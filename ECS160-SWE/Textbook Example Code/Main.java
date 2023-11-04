class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Deck deck = new Deck();
        deck.aCards.add(new Card(Rank.ACE, Suit.CLUBS));
        deck.aCards.add(new Card(Rank.TEN, Suit.HEARTS));

        for (Card card : deck.aCards) {
            System.out.println("Suit: " + card.getSuit() + ", Rank: " + card.getRank());
        }
    }
}