public class Main {

    public static void main(String[] args) {
        var music = new MusicEngine();

        // Все песни
        var allSongs = music.find().all().results();

        // Песни, выпущенные в 2017 году
        var songs2017 = music.find()
                .year("2017")
                .results();

        // Песни жанра Alternative, выпущенные в 2012 году
        var alternative2016 = music.find()
                .genre("Alternative")
                .year("2016")
                .results();

        // Песни альбома Post Traumatic
        var postTraumaticAlbum = music.find()
                .album("Post Traumatic")
                .results();

        // Песни группы LINKIN PARK 2000 года
        var linkinPark2000 = music.find()
                .author("LINKIN PARK")
                .year("2000")
                .results();
    }
}
