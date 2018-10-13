import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Song {
    private static final String DEFAULT_VALUE = "UNKNOWN";
    private Map<String, Object> info;

    public Song(Map<String, Object> info) {
        this.info = info;
    }


    private final static String TITLE_DESCRIPTOR = "title";

    public Object getTitle() {
        return info.getOrDefault(TITLE_DESCRIPTOR, DEFAULT_VALUE);
    }


    private final static String AUTHOR_DESCRIPTOR = "author";

    public Object getAuthor() {
        return info.getOrDefault(AUTHOR_DESCRIPTOR, DEFAULT_VALUE);
    }


    private final static String FEAT_DESCRIPTOR = "feat";

    public ArrayList getFeat() {
        return (ArrayList) info.getOrDefault(FEAT_DESCRIPTOR, new ArrayList<>());
    }


    private final static String GENRE_DESCRIPTOR = "genre";

    public String getGenre() {
        return (String) info.getOrDefault(GENRE_DESCRIPTOR, DEFAULT_VALUE);
    }


    private final static String ALBUM_DESCRIPTOR = "album";

    public Object getAlbum() {
        return info.getOrDefault(ALBUM_DESCRIPTOR, DEFAULT_VALUE);
    }


    private final static String YEAR_DESCRIPTOR = "year";

    public Object getYear() {
        return info.getOrDefault(YEAR_DESCRIPTOR, DEFAULT_VALUE);
    }


    @Override
    protected Song clone() {
        var songInfo = new HashMap<>(this.info);
        return new Song(songInfo);
    }
}