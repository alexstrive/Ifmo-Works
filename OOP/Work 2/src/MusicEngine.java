public class MusicEngine {
    private SongManager songManager;

    public MusicEngine() {
        this.songManager = new SongManager("main");
    }

    public SearchQuery find() {
        return this.songManager.createSearchQuery();
    }
}
