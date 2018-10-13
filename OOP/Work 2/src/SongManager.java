import org.json.JSONArray;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import static java.util.stream.Collectors.toList;

public class SongManager {
    private List<Song> songs;

    private static final String SONG_DIRECTORY = "songs";

    public SongManager(String managerName) {
        var filePath = Loader.getFilePath(SONG_DIRECTORY + "/" + managerName + ".json");
        var fileContent = Loader.getFileContent(filePath);
        var jsonSongInfoArray = new JSONArray(fileContent);

        var items = jsonSongInfoArray.toList().stream()
                .map(info -> (Map) info)
                .map(Song::new)
                .collect(toList());

        this.songs = new ArrayList<>(items);
    }

    public SearchQuery createSearchQuery() {
        return new SearchQuery(new ArrayList<>(this.songs));
    }
}
